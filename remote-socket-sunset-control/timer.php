<?php
date_default_timezone_set('TIMEZONE');
$current_date = date("Y-m-d");


$latitude = 0; //POSITION LAT
$longitude = 0; //POSITION LONG

$sun_info = date_sun_info(strtotime($current_date), $latitude, $longitude);

function timeFormat($val) {
	return date("Y-m-d H:i:s", $val);
}
$sunrise = $sun_info['sunrise'];
$sunset = $sun_info['sunset'];

$current_time = time();
$socket_off = strtotime($current_date . " 23:00:00");
$socket_on = $sunset;

function switch_socket($i) {
	shell_exec("cd /home/pi/remote-socket/ && ./control ". strval($i));
}

if ($current_time > $socket_on && $current_time < $socket_off ) {
	switch_socket(1);
}
else {
	switch_socket(0);
}

?>
