package com.example.acmshyryihw26_2

import javafx.fxml.FXML
import javafx.scene.control.TextArea

class ShyryiController {
    @FXML
    private lateinit var inputTextArea: TextArea

    @FXML
    private lateinit var outputTextArea: TextArea

    @FXML
    private fun onSortButtonClick() {
        val numbersAsString = inputTextArea.text
                .replace("[^\\d]+".toRegex(), ",")
                .replace("^\\D+|\\D+$".toRegex(), "")
                .split(",")

        val numbers = IntArray(numbersAsString.size)
        for (i in numbersAsString.indices) {
            numbers[i] = numbersAsString[i].toInt()
        }

        quickSort(numbers, 0, numbers.size - 1)

        for (i in numbers.indices) {
            outputTextArea.appendText(numbers[i].toString() +
                    (if (i < numbers.size - 1) ", " else "."))
        }
    }

    private fun quickSort(array: IntArray, low: Int, high: Int) {
        if (low < high) {
            val pivotIndex = partition(array, low, high)
            quickSort(array, low, pivotIndex - 1)
            quickSort(array, pivotIndex + 1, high)
        }
    }

    private fun partition(array: IntArray, low: Int, high: Int): Int {
        val pivot = array[high]
        var i = low - 1

        for (j in low until high) {
            if (array[j] < pivot) {
                i++
                swap(array, i, j)
            }
        }

        swap(array, i + 1, high)
        return i + 1
    }

    private fun  swap(array: IntArray, i: Int, j: Int) {
        val temp = array[i]
        array[i] = array[j]
        array[j] = temp
    }
}