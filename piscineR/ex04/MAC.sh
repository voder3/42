ifconfig | grep "ether" | sed 's/ether//g' | tr -d '\t\r' | tr -d ' '
