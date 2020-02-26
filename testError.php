#!/usr/bin/php
<?php

require_once('Logger.php.inc');

$rabbitConfig = 'rabbit.ini';
$log = new Logger('dbtest',$rabbitConfig);


$log->logError("Test","DEBUG","This is a test Error");
$log->logDebug("test","this is a test debug");

?>

