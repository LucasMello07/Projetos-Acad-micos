package com.mycompany.olajavafx;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;


/**
 * JavaFX App
 */
public class App extends Application {

    @Override
    public void start(Stage stage) {
        String javaVersion = SystemInfo.javaVersion();
        String javafxVersion = SystemInfo.javafxVersion();

        
        Label label = new Label("Hello, JavaFX "
                        + javafxVersion
                        + ", running on Java "
                        + javaVersion + ".");
        
        Label frase = new Label("Aqui tem um bando de loco!");
        
        StackPane painel = new StackPane(label);
        painel.getChildren().add(frase);
                
        Scene scene = new Scene(painel, 320, 240);
        
        stage.setTitle("Minha primeira aplicação JavaFX");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }

}