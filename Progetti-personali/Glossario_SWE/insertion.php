<?php
    require("interrogation.php");

    echo"<html><head><link rel='stylesheet' href='stile.css' /></head><body>";

    echo"<div><a href='index.php'>Lista</a></div>";
    
    $connessione=connessione();

    echo"<div>";

    if($_SERVER["REQUEST_METHOD"]=="POST"){
        if(empty($_POST["nome"]) || empty($_POST["definizione"])){
            echo"<p>Form non compilata correttamente</p>";
        }
        else{
            if(!$result=$connessione->query("INSERT INTO glossario(`NOME`,`DEFINIZIONE`,`ALTRO`) VALUE (\"".$_POST["nome"]."\",\"".$_POST["definizione"]."\",\"".$_POST["altro"]."\")")){
                echo"errore della query: ".$connessione->error.".";
                exit();
            }
            else{
                echo"<p> Inserimento avvenuto con successo";
            }
        }
    }
    else{
        echo"<form action='insertion.php' method='post'>
        <label id='nome'>Nome:<input type='text' value='' id='nome' name='nome'/></label>
        <label id='definizione'>Definzione:<textarea value='' id='definizione' cols='40' rows='15' name='definizione'></textarea></label>
        <label id='altro'>Altro:<textarea value='' id='altro' cols='40' rows='15' name='altro'></textarea></label>
        <input type='submit'value='Inserisci' />
        <input type='reset' value='Reset' />
        </form>";
    }
    echo"</div>";

    echo"</body></html>"
?>