import anki_vector
import time


def main():
    args = anki_vector.util.parse_command_args()
    with anki_vector.Robot(args.serial) as robot:
        while(1):
            current_gyro = robot.gyro
            print("Robot gyro {0}".format(current_gyro))
            time.sleep(0.050)


if __name__ == "__main__":
    main()

