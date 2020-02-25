#!/usr/bin/php
<?php

require_once('rabbitMQLib.inc');
require_once('get_host_info.inc');
require_once('path.inc');


class errorLogger
{
	private $sending_server;
	private $error_type;
	private $error_level;
	private $error_message;
	private $error_timestamp;
		
	
	private $rabbit_server;
	private $rabbit_message;
	
	function __construct($error_sender, $rabbitServ)
	{
		$this->rabbit_server = new rabbitMQClient($rabbitServ,"ErrorLogging");
		$this->sending_server = $error_sender;
	}

	function logError($errType, $errLevel, $errMessage)
	{
		$this->error_timestamp = date("m/d/Y h:i:s");
		$this->error_type = $errType;
		$this->error_level = $errLevel;
		$this->error_message = $errMessage;

		$this->rabbit_message = $this->error_timestamp."\t".$this->sending_server."\t".$this->error_type."\t".$this->error_level."\t".$this->error_message;

		$response = $this->rabbit_server->publish($this->rabbit_message);
		echo "Logged Error\n";
		print_r($response);
	}
}


