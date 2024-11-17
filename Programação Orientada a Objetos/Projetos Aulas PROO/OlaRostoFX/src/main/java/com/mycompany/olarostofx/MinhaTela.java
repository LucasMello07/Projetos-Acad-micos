package com.mycompany.olarostofx;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Arc;
import javafx.scene.shape.Circle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;


/**
 * JavaFX MinhaTela
 */
public class MinhaTela extends Application {

    @Override
    public void start(Stage stage) {
        // cria o rosto
        Circle rosto = new Circle(125, 125, 80);
        rosto.setFill(Color.BISQUE);
        rosto.setStroke(Color.BROWN);
        
        // cria o olho esquerdo
        Circle olhoEsquerdo = new Circle(86, 100, 10);
        olhoEsquerdo.setFill(Color.BLUE);
        olhoEsquerdo.setStroke(Color.WHITE);
        
        // cria o olho direito
        Circle olhoDireito = new Circle(162, 100, 10);
        olhoDireito.setFill(Color.BLUE);
        olhoDireito.setStroke(Color.WHITE);
        
        // cria a boca
        Arc boca = new Arc(125, 150, 45, 35, 0, -180);
        boca.setFill(Color.RED);
        
        // cria um texto
        Text texto = new Text(50, 240,
                "Olá, sou o Bob!");
        texto.setFill(Color.BLUEVIOLET);
        texto.setFont(Font.font("Algerian", 20));        
        
        // container com os elementos do rosto
        Group raiz = new Group(rosto,
                olhoEsquerdo, olhoDireito,
                boca, texto);

        // configurar a cena
        Scene cena = new Scene(raiz, 250, 320);
        
        // prepara o stage
        stage.setScene(cena);
        stage.setTitle("Olá!");        
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }

}