package com.example.acmshyryihw26_1;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class ShyryiApplication extends Application {

    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(ShyryiApplication
                .class.getResource("acmshyryihw26_1-view.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 510, 250);
        stage.setTitle("Ширий Богдан. " +
                "АМО Домашнє завдання №26.1, варіант №24");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}