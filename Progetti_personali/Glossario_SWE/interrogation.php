<?php
    function connessione(){
        $host = "localhost";
        $user = "root";
        $password = "";
        $db = "glossarioswe";
        $connessione = mysqli_connect($host,$user, $password, $db);

        if($connessione->connect_error){
            die('connessione fallita '.$connessione->connect_error);
        }
        return $connessione;
    }
?>