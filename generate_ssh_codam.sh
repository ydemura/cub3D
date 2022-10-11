#!/bin/bash
cd ~/.ssh
yes | ssh-keygen -t rsa -b 2048 -C "demjula@gmail.com" -f "/Users/ydemura/.ssh/id_rsa" -P "mypath"
pbcopy < id_rsa.pub

