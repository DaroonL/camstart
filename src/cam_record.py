from picamera import PiCamera
from time import sleep

def record(path, framerate): #path is a string
    camera = PiCamera()
    camera.framerate = framerate
    camera.start_preview()
    camera.start_recording(path) #location file is deposited
    sleep(5) 
    camera.stop_recording()
    camera.stop_preview()
    return