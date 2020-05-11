#!/bin/bash
cp stockLogger.service /etc/systemd/system/stockLogger.service
systemctl enable stockLogger.service
systemctl start stockLogger.service
systemctl status stockLogger.service
