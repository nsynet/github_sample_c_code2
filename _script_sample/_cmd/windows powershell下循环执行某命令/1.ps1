for ($i=1; $i -le 5; $i++) {
 Write-Host "-->test $i"
adb shell cat /sys/camera_avm/camera_status_value
 Start-Sleep -Seconds 2
}