package com.example.acmshyryihw21;

import javafx.fxml.FXML;
import javafx.scene.control.TextArea;

import java.util.*;

public class ShyryiController {
    @FXML
    private TextArea textInputTextArea;
    @FXML
    private TextArea letterInputTextArea;
    @FXML
    private TextArea textOutputTextArea;
    @FXML
    private TextArea hashMapOutputTextArea;
    @FXML
    protected void onInvestigateButtonClick() {
        String inputText = textInputTextArea.getText()
                .replaceAll("[^a-zA-Z0-9\\s]", "");
        textOutputTextArea.setText("");
        hashMapOutputTextArea.setText("");

        ArrayList<Integer> wordStartIndexes = new ArrayList<>();
        HashMap<Integer, String> resultsHashMap = new LinkedHashMap<>();

        // Знаходимо індекси на початок слів
        for (int i = 0; i < inputText.length(); i++) {
            if (i == 0 && !Character.isWhitespace(inputText.charAt(i))) {
                wordStartIndexes.add(i);
            } else if (i > 0 && !Character.isWhitespace(inputText.charAt(i))
                    && Character.isWhitespace(inputText.charAt(i - 1))) {
                wordStartIndexes.add(i);
            }
        }

        // Виводимо слова, що починаються зі шуканої літери
        for (int startIndex : wordStartIndexes) {
            String word = getWordFromIndex(inputText, startIndex);
            if (Character.toLowerCase(word.charAt(0)) == Character
                    .toLowerCase(letterInputTextArea.getText().charAt(0))) {
                textOutputTextArea.appendText((word + " "));
                resultsHashMap.put(startIndex, word);
            }
        }

        // Сортуємо решту слів в алфавітному порядку
        Collections.sort(wordStartIndexes, (x, y) -> {
            String wordX = getWordFromIndex(inputText, x);
            String wordY = getWordFromIndex(inputText, y);
            return wordX.compareToIgnoreCase(wordY);
        });

        // Виводимо відсортовані слова
        for (int startIndex : wordStartIndexes) {
            String word = getWordFromIndex(inputText, startIndex);
            if (Character.toLowerCase(word.charAt(0)) != Character
                    .toLowerCase(letterInputTextArea.getText().charAt(0))) {
                textOutputTextArea.appendText((word + " "));
                resultsHashMap.put(startIndex, word);
            }
        }

        // Виводимо результати збережені в LinkedHashMap
        for (Map.Entry<Integer, String> entry : resultsHashMap.entrySet()) {
            hashMapOutputTextArea.appendText(entry
                    .getKey() + " - " + entry.getValue()
             + (entry.getKey() == wordStartIndexes
                    .get(wordStartIndexes.size() - 1) ? "" : ", "));
        }
    }
    private static String getWordFromIndex(String inputText, int startIndex) {
        int endIndex = inputText.indexOf(' ', startIndex);
        if (endIndex == -1) {
            endIndex = inputText.length();
        }
        return inputText.substring(startIndex, endIndex);
    }
}