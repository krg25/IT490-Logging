#!/usr/bin/php
<?php#

require_once('rabbitMQLib.inc');


function logProcessor($logMessage)
{
	
		$logFile = 'stockSystemLog.txt';	
		$file = fopen($logFile,'a');
		fwrite($file,$logMessage);
		$fclose($file);
	

}


$server = new rabbitMQServer("rabbit.ini","ErrorLogging");

$server->process_requests('logProcessor');
exit();
