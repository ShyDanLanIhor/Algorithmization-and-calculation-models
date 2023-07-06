from tkinter import Tk, Button, Label, filedialog, messagebox
from PIL import Image, ImageTk
import tkinter.font as tkfont
import cv2

#-----------------------------------------#
# --- ��������� ��� ��������� ������ --- #
#-----------------------------------------#

isFirst = False

# --- �������� ����� ��������� --- #
def change_picture_button_click():
    global isFirst

    if isFirst:
        # ���� ������ �������� �� ��������
        change_picture_button.configure(text = "Change to origin picture")

        # ���� ��������� ����������
        image = Image.open("images/OutputImage.jpg")
        
        # ���� ������ ����������
        image = image.resize((580, 330), Image.ANTIALIAS)
            
        # ����������� ���������� � ������ PhotoImage
        photo = ImageTk.PhotoImage(image)

        # ��������� ���������� � ����� label
        label.configure(image=photo)
        label.image = photo  # ���������� �������� ��������� �� ����������
    else:
        # ���� ������ �������� �� ��������
        change_picture_button.configure(text = "Change to final picture")

        # ���� ��������� ����������
        image = Image.open("images/InputImage.jpg")
        
        # ���� ������ ����������
        image = image.resize((580, 330), Image.ANTIALIAS)
            
        # ����������� ���������� � ������ PhotoImage
        photo = ImageTk.PhotoImage(image)

        # ��������� ���������� � ����� label
        label.configure(image=photo)
        label.image = photo  # ���������� �������� ��������� �� ����������
    isFirst = not isFirst

# --- ����� ����� --- #
def find_faces_button_click():

    # ������������ ����
    image = cv2.imread("images/InputImage.jpg")

    # ������������ � ������ ����� (��� ���������� ������ ���������)
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # ������������ ���������� ������������� �������
    faceCascade = cv2.CascadeClassifier(cv2.data.haarcascades + "haarcascade_frontalface_alt.xml")

    # ��������� �������
    faces = faceCascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=3, minSize=(30, 30))

    # ��� �������� �������
    maxFaces = 9  # ����������� ������� �����, ��� �� ������ �������
    numFaces = min(len(faces), maxFaces)
       
    # ���������� ����� ������ ��� �������
    for i in range(numFaces):
        (x, y, w, h) = faces[i]
        center = (x + w // 2, y + h // 2)
        axes = (w // 2, h // 2)
        cv2.ellipse(image, center, axes, 0, 0, 360, (0, 255, 0), 2)

    # ���������� ���������� � ����
    cv2.imwrite("images/OutputImage.jpg", image)

    # ���� ��������� ����������
    image = Image.open("images/OutputImage.jpg")

    # ���� ������ ����������
    image = image.resize((580, 330), Image.ANTIALIAS)
    
    # ����������� ���������� � ������ PhotoImage
    photo = ImageTk.PhotoImage(image)

    # ��������� ���������� � ����� label
    label.configure(image=photo)
    label.image = photo  # ���������� �������� ��������� �� ����������

    # ���� ������ �������� �� ��������
    change_picture_button.configure(text = "Change to origin picture", state = "normal")

# --- ������������ ���������� --- #
def load_picture_button_click():
    global isFirst

    # ³������� ���������� ���� ������ �����
    file_path = filedialog.askopenfilename(filetypes=[("Images", "*.png;*.jpg;*.jpeg")])
    
    try:
        # ���������� ����������
        image = Image.open(file_path)
        
        # ���� ������ ����������
        image = image.resize((580, 330), Image.ANTIALIAS)
        
        # ����������� ���������� � ������ PhotoImage
        photo = ImageTk.PhotoImage(image)
        
        # ��������� ���������� � ����� label
        label.configure(image=photo)
        label.image = photo  # ���������� �������� ��������� �� ����������
        
        # ���������� ����������
        Image.open(file_path).save("images/InputImage.jpg")

        # ���� ������ �������� �� ��������
        find_faces_button.configure(text = "Find faces", state = "normal")
        change_picture_button.configure(text = "Waiting for final result", state = "disabled")
        isFirst = False

    except Exception as e:
        messagebox.showinfo("That`s an error my friend", e)

#-----------------------------------------#
# --- ��������� ����� �� �� �������� --- #
#-----------------------------------------#

# ��������� ����
window = Tk()
font = tkfont.Font(family="Times New Roman", size=14)

# ������������ ����
window.title("Bohdan Shyryi. ACM HomeWork #24.2, variant: #24")
window.geometry("600x400")

# ��������� ��������
change_picture_button = Button(window, text="Waiting for final result", state = "disabled", 
                               width=20, height=1, font = font, command=change_picture_button_click)
change_picture_button.place(x=10, y=350)

find_faces_button = Button(window, text="Waiting for loading", state = "disabled", 
                           width=16, height=1, font = font, command=find_faces_button_click)
find_faces_button.place(x=240, y=350)

load_picture_button = Button(window, text="Load new picture", width=14, height=1, 
                             font = font, command=load_picture_button_click)
load_picture_button.place(x=430, y=350)

# ��������� ����������� ����������
image = Image
label = Label()
label.pack()

# ������ ��������� ����� ������� ����
window.mainloop()