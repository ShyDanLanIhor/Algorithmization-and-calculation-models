package com.example.acmshyryihw26_2

import javafx.application.Application
import javafx.fxml.FXMLLoader
import javafx.scene.Scene
import javafx.stage.Stage

class ShyryiApplication : Application() {
    override fun start(stage: Stage) {
        val fxmlLoader = FXMLLoader(ShyryiApplication
        ::class.java.getResource("acmshyryihw26_2-view.fxml"))
        val scene = Scene(fxmlLoader.load(), 510.0, 250.0)
        stage.title = "Ширий Богдан. " +
                "АМО Домашнє завдання №26.2, варіант №24"
        stage.scene = scene
        stage.show()
    }
}

fun main() {
    Application.launch(ShyryiApplication::class.java)
}