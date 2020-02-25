#!/usr/bin/php
<?php

require_once('rabbitMQLib.inc');


class errorLogger
{
	private $sending_server;
	private $error_type;
	private $error_level;
	private $error_message;
	private $timestamp = date("m/d/Y H:i:s");	
	
	private $rabbit_server = "";
	private $rabbit_message;
	
	function __construct($error_sender, $rabbit_server);
	{
		$this->rabbit_server = new rabbitMQClient($this>rabbit_server,"errorReporting");
		$this->sending_server = $this->error_sender;
	}

	function logError($errType, $errLevel, $errMessage)
	{
		$this->error_type = $this->errType;
		$this->error_level = $this->error_level;
		$this->error_message = $this->errMessage;

		$this->rabbit_message = $timestamp.\t.$sending_server.\t.$error_type.\t.$error_level.\t.$error_message;

		$response = $client->publish($rabbit_message);
		echo "Logged Error";
		printr($response);
	}
}


