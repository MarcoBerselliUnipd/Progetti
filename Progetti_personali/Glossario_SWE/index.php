<?php
    require("interrogation.php");

    echo"<html><head><link rel='stylesheet' href='stile.css' /></head><body>";

    echo"<div><a id='link' href='insertion.php'>Inserisci</a></div>";

    $connessione=connessione();

    echo"<div>";

    if(!$result=$connessione->query("SELECT * FROM glossario")){
        echo"errore della query: ".$connessione->error.".";
        exit();
    }
    else{
        if($result->num_rows > 0){
            echo "<form action='update.php' method='POST' id='lista'>";
            while($row = $result -> fetch_array(MYSQLI_ASSOC)){

                echo "<div>";
                echo "<button class='bottoneModifica' value=\"".$row['NOME']."\" name='bottoneModifica'>Modifica</button>";
                echo "<div><strong>".$row['NOME']."</strong></div>";
                echo "<div class='definizione'>".$row['DEFINIZIONE']."</div>";
                echo "<div class='altro'>".$row['ALTRO']."</div>";
                echo "</div>";
            }
            echo "</form>";
        }
        $result->free();
    }

    echo"</div>";

    echo"</body></html>"
?>
