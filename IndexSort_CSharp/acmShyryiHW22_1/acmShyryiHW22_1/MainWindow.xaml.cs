using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;
using System.Windows;

namespace acmShyryiHW22_1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Investigate_Click(object sender, RoutedEventArgs e)
        {
            string inputText = Regex.Replace(textInputTextBox.Text, "[^a-zA-Z0-9\\s]", "");
            textOutputTextBox.Text = ""; dictionaryOutputTextBox.Text = "";

            List<int> wordStartIndexes = new List<int>();
            Dictionary<int, string> resultsDictionary = new Dictionary<int, string>();

            // Знаходимо індекси на початок слів
            for (int i = 0; i < inputText.Length; i++)
            {
                if (i == 0 && !char.IsWhiteSpace(inputText[i]))
                    wordStartIndexes.Add(i);
                else if (i > 0 && !char.IsWhiteSpace(inputText[i]) 
                    && char.IsWhiteSpace(inputText[i - 1]))
                    wordStartIndexes.Add(i);
            }
            // Виводимо слова, що починаються зі шуканої літери
            foreach (int startIndex in wordStartIndexes)
            {
                string word = GetWordFromIndex(inputText, startIndex);
                if (char.ToLower(word[0]) == char.ToLower(letterInputTextBox.Text[0]))
                {
                    textOutputTextBox.Text += word + " ";
                    resultsDictionary[startIndex] = word;
                }
            }
            // Сортуємо решту слів в алфавітному порядку
            wordStartIndexes.Sort((x, y) =>
            {
                string wordX = GetWordFromIndex(inputText, x);
                string wordY = GetWordFromIndex(inputText, y);
                return string.Compare(wordX.ToLower(), wordY.ToLower());
            });
            // Виводимо відсортовані слова
            foreach (int startIndex in wordStartIndexes)
            {
                string word = GetWordFromIndex(inputText, startIndex);
                if (char.ToLower(word[0]) != char.ToLower(letterInputTextBox.Text[0]))
                {
                    textOutputTextBox.Text += word + " ";
                    resultsDictionary[startIndex] = word;
                }
            }
            // Виводимо результати збережені в словнику
            foreach (var kvp in resultsDictionary)
            {
                dictionaryOutputTextBox.Text += kvp.Key + " - " + kvp.Value + 
                    (kvp.Equals(resultsDictionary.Last()) ? "" : ", ");
            }
            static string GetWordFromIndex(string inputText, int startIndex)
            {
                int endIndex = inputText.IndexOf(' ', startIndex);
                if (endIndex == -1)
                    endIndex = inputText.Length;
                return inputText.Substring(startIndex, endIndex - startIndex);
            }
        }
    }
}
