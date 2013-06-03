<?php

//require_once 'Log.php'; #TODO

class LogManager {

public function debug($message, $actor){
	//global $LOGROOT;
	$transid = session_id();
	//echo $message;
	$filename = LOGROOT.'/debug.log';
	$this->logToFile($filename, date("Y-m-d H:i:s") . " SID:[". $transid. "] ". $message);
}
public function info($message, $actor){ 
	//global $LOGROOT;
	$transid = session_id();
	//echo $message;
	$filename = LOGROOT.'/info.log';
	//$this->logToFile($filename, $message);
	$this->logToFile($filename, date("Y-m-d H:i:s") . " SID:[". $transid ."] ". $message);
}

public function query($message, $actor){ 
	//global $LOGROOT;
	$transid = session_id();
	//echo $message;
	$filename = LOGROOT.'/query.log';
	//$this->logToFile($filename, $message."\n--");
	/*
		Logs query in pseudo-XML
	*/
	$this->logToFile($filename, "<query sessionID=\"".$transid."\" timestamp=\"" . date("Y-m-d H:i:s") . "\">\n". $message . "\n</query>");
}
/////////////////////////////////////////

static function logToFile($filename, $msg)
{ 
	// open file
	$fd = fopen($filename, "a");
	// write string
	fwrite($fd, $msg . "\n");
	// close file
	fclose($fd);
}

}
?>
