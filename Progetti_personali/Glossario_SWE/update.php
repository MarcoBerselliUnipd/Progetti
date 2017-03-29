<?php
    require("interrogation.php");

    echo"<html><head><link rel='stylesheet' href='stile.css' /></head><body>";

    echo"<div><a href='index.php'>Lista</a></div>";

    $connessione=connessione();

    echo"<div>";

    if($_SERVER["REQUEST_METHOD"]=="POST"){
        if(isset($_POST['bottoneModifica'])){
            if(empty($_POST["bottoneModifica"])){
                echo"<p>Qualcosa è andato storto nel passaggio della modifica</p>";
            }
            else{
                if(!$result=$connessione->query("SELECT * FROM glossario WHERE NOME=\"".$_POST["bottoneModifica"]."\";")){
                    echo"errore della query: ".$connessione->error.".";
                exit();
                }
                else{
                    if($result->num_rows > 0){
                        while($row = $result -> fetch_array(MYSQLI_ASSOC)){
                            echo"<form action='update.php' method='post'>
                            <input type='hidden' value=\"".$_POST["bottoneModifica"]."\" name='nomePrecedente'/>
                            <label id='nome'>Nome:<input type='text' value=\"".$row['NOME']."\" id='nome' name='nome'/></label>
                            <label id='definizione'>Definzione:<textarea id='definizione' cols='40' rows='15' name='definizione'>".$row['DEFINIZIONE']."</textarea></label>
                            <label id='altro'>Altro:<textarea id='altro' cols='40' rows='15' name='altro'>".$row['ALTRO']."</textarea></label>
                            <input type='submit'value='Modifica/Elimina' id='submit' />
                            <label>Elimina<input type='checkbox' value='elimina' name='eliminaCheck'/></label>
                            </form>";
                        }
                    }
                    $result->free();
                }
            }
        }

        if(isset($_POST['nomePrecedente']) && isset($_POST['nome'])&& isset($_POST['definizione']) && isset($_POST['altro'])){
            if(isset($_POST['eliminaCheck'])){
                if(!$result=$connessione->query("DELETE FROM glossario WHERE `NOME`='".$_POST["nomePrecedente"]."'")){
                        echo"errore della query: ".$connessione->error.".";
                        exit();
                    }
                    else{
                        echo"<p>Eliminazione avvenuta con successo";
                    }

            }
            else {
                if(empty($_POST["nome"]) || empty($_POST["definizione"])){
                    echo"<p>Form non compilata correttamente</p>";
                }
                else{
                    if(!$result=$connessione->query("UPDATE glossario SET `NOME`=\"".$_POST["nome"]."\",`DEFINIZIONE`=\"".$_POST["definizione"]."\",`ALTRO`=\"".$_POST["altro"]."\" WHERE `NOME`='".$_POST["nomePrecedente"]."'")){
                        echo"errore della query: ".$connessione->error.".";
                        exit();
                    }
                    else{
                        echo"<p>Aggiornamento avvenuto con successo";
                    }
                }
            }
        }

    }
    else{
        echo"<p>Dove vai se il _POST non ce l'hai?</p>";
    }

    echo"</div>";

    echo"</body></html>"
?>
