<?php


server_private.pem
server_public.pem

cifraRisposta()      //Con chiave privata
decifraRichiesta()   //Con chiave pubblica dell'utente


//le richieste sono create con N diverse chiavi private

//SETUP INIZIALE: generazione chiavi pubblica/privata del server

//Setup utente: generazione chiave PRIVATA utente e download (1 volta sola)
//		download chiave PUBBLICA del server 

function secure_request($user, $message){ 
	//RICHIESTA user   -> server cifrata dall'utente con la chiave user_private.pem e server_public.pem
	//--> decipher con la chiave pubblica server_public.pem 
}
function secure_response($user, $message){ 
	//RISPOSTA  server -> user cifrata dal server con la chiave server_private.pem e user_public.pem
}


?>
