<?php

require_once("env.inc");

class SecurityManager 
{

public function createKeys($passphrase){
	$privateKey = openssl_pkey_new(array(
        	'private_key_bits' => 1024,
        	'private_key_type' => OPENSSL_KEYTYPE_RSA,
	));
	openssl_pkey_export_to_file($privateKey, PRIVATE_KEY, $passphrase);
	$keyDetails = openssl_pkey_get_details($privateKey);
	file_put_contents(PUBLIC_KEY, $keyDetails['key']);
}



//Client side
public function cryptRequest($clearText,$passphrase){
	//$pubKey = openssl_get_publickey(file_get_contents(PUBLIC_KEY));
	///!!!
	$clearText  = pack('V', strlen($clearText)) . $clearText;

	$privateKey = openssl_get_privatekey(file_get_contents(USER_PRIVATE_KEY), $passphrase);
	//openssl_public_encrypt($clearText, $encryptedData, $privateKey);
	openssl_private_encrypt($clearText, $encryptedData, $privateKey);
	return base64_encode($encryptedData);
}

/**
	De-Cipher with PUBLIC KEY
*/
public function decrypt($encryptedData){
	$pubKey = openssl_get_publickey(file_get_contents(PUBLIC_KEY));
	openssl_public_decrypt($encryptedData, $clear,  $pubKey);
	var_dump($clear);
	return $clear;
}

//Server side
public function decryptRequest($encryptedData, $passphrase){
        //$pubKey = openssl_get_publickey(file_get_contents(PRIVATE_KEY));
        $privKey = file_get_contents(SERVER_PRIVATE_KEY);
	$privatekey = openssl_get_privatekey($privKey,$passphrase);

	//openssl_pkey_get_private($privatekey,$passphrase);

	$decoded_source = base64_decode($source);
	//$privatekey = openssl_get_privatekey(SERVER_PRIVATE_KEY,$passphrase);
        if (openssl_private_decrypt($decoded_source, $clear,  $privatekey) ){
		echo "DECRYPTED";
	} else {
		echo "TROUBLE HERE";
	}
        var_dump($clear);
        return $clear;
}


public function xxx(){
    $class = 'SecurityManager';
    $object = new $class();
    echo $object->methods();
}


} ?>
