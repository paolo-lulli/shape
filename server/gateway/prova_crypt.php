<?php
/*

http://www.webtatic.com/blog/2009/07/php-public-key-cryptography/

*/
$privateKey = openssl_pkey_new(array(
        'private_key_bits' => 1024,
        'private_key_type' => OPENSSL_KEYTYPE_RSA,
));
//openssl_pkey_export_to_file($privateKey, '/path/to/privatekey', $passphrase);
$privateKey="aaaa"; 
$passphrase="aaaa";
openssl_pkey_export_to_file($privateKey, '.', $passphrase);
 
// get the public key $keyDetails['key'] from the private key;
//$keyDetails = openssl_pkey_get_details($privateKey);
//file_put_contents('/path/to/publickey', $keyDetails['key']);

?>

