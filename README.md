# ErrorLog Processor

Open up the anacrontab at /var/anacrontab

Add to the bottom: @hourly 0 ErrorListener php -s ~/git/IT490-Logging/ErrorListener.php

Save and exit, your php path may vary. This will ensure that the errorlistener will run when you start your machine and every hour if not already running. This way we will get all errors from the log.
