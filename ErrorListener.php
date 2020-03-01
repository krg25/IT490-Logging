#!/usr/bin/php
<?php

require_once('rabbit/rabbitMQLib.inc');


function logProcessor($logMessage)
{
		$logFile = 'stockSystemLog.txt';	
		$file = fopen($logFile,'a');
		fwrite($file,$logMessage."\n");
		fclose($file);
	

}


$server = new rabbitMQServer("rabbit/rabbit.ini","ErrorLogging");

$server->process_requests('logProcessor');


exit();
?>
