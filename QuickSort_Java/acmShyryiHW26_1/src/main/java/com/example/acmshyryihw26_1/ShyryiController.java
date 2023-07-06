package com.example.acmshyryihw26_1;

import javafx.fxml.FXML;
import javafx.scene.control.TextArea;

public class ShyryiController {
    @FXML
    private TextArea inputTextArea;
    @FXML
    private TextArea outputTextArea;
    @FXML
    protected void onInvestigateButtonClick() {
        String[] numbersAsString = inputTextArea.getText()
                .replaceAll("[^\\d]+", ",")
                .replaceAll("^\\D+|\\D+$", "")
                .split(",");

        int[] numbers = new int[numbersAsString.length];
        for (int i = 0; i < numbersAsString.length; i++) {
            numbers[i] = Integer.parseInt(numbersAsString[i]);
        }

        quickSort(numbers, 0, numbers.length - 1);

        for (int i = 0; i < numbers.length; i++)
        {
            outputTextArea.appendText(numbers[i] +
                    (i < numbers.length - 1 ? ", " : "."));
        }
    }
    public static void quickSort(int[] array, int low, int high) {
        if (low < high) {
            int pivotIndex = partition(array, low, high);
            quickSort(array, low, pivotIndex - 1);
            quickSort(array, pivotIndex + 1, high);
        }
    }

    public static int partition(int[] array, int low, int high) {
        int pivot = array[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (array[j] < pivot) {
                i++;
                swap(array, i, j);
            }
        }

        swap(array, i + 1, high);
        return i + 1;
    }

    public static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}