#!/usr/bin/php
<?php

require_once('ErrorLogger.php.inc');

$rabbitConfig = 'rabbit.ini';
$log = new errorLogger('dbtest',$rabbitConfig);


$log->logError("Test","DEBUG","This is a test Error");

?>

