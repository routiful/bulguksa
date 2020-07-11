import anki_vector
import io
import sys
import time
from PIL import Image


def main():
    args = anki_vector.util.parse_command_args()

    with anki_vector.Robot(args.serial) as robot:
        captured_image = robot.camera.capture_single_image()

        # Load an image
        pil_image = captured_image.raw_image
        pil_image = pil_image.resize((184, 96))

        # Convert the image to the format used by the Screen
        print("Display image on Vector's face...")
        screen_data = anki_vector.screen.convert_image_to_screen_data(pil_image)

        duration_s = 4.0
        robot.screen.set_screen_with_image_data(screen_data, duration_s)
        time.sleep(duration_s)


if __name__ == "__main__":
    main()

