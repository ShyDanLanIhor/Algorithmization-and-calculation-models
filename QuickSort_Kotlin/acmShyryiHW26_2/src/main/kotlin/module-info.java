module com.example.acmshyryihw26_2 {
    requires javafx.controls;
    requires javafx.fxml;
                requires kotlin.stdlib;
    
                            
    opens com.example.acmshyryihw26_2 to javafx.fxml;
    exports com.example.acmshyryihw26_2;
}