from picamera2 import Picamera2
from time import sleep

def record(path, framerate): #path is a string
    camera = Picamera2()
    camera.framerate = framerate
    camera.start_preview()
    camera.start_recording(path) #location file is deposited
    sleep(5) 
    camera.stop_recording()
    camera.stop_preview()
    return

if __name__ == "__main__":
    if len(sys.argv) == 3:  # Check if the number of arguments is correct
        path = sys.argv[1]  # First argument: file path
        framerate = int(sys.argv[2])  # Second argument: frame rate, convert to integer
        record(path, framerate)
    else:
        print("Usage: python camera_record.py <path> <framerate>")