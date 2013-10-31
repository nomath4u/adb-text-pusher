# This script should launch the camera app and take a picture on an android phone

echo "Starting the Camera App in Photo mode"

am start -a android.media.action.IMAGE_CAPTURE

echo "Sleeping 3 seconds"

sleep 3

echo "Taking the picture"

input keyevent 27

