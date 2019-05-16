This is an OpenGL-based 3D demo.
It contains a pair of latin dancer.
program control is specified as the following:

'1' - Male Dancer (press 1 then control the male dancer)
'2' - Female Dancer (press 2 then control the female dancer)

the following button will move in oppsite direction when pressed with "shift":

Body:
'q' - Translte body along x-axis
'a' - Translte body along y-axis
'z' - Translte body along z-axis
'w' - Rotate body around x-axis
's' - Rotate body around y-axis
'x' - Rotate body around z-axis'
Left Arm:
'3' - Rotate left upper arm around x-axis
'4' - Rotate left upper arm around y-axis
'5' - Rotate left upper arm around z-axis
'e' - Rotate left lower arm around x-axis
'r' - Rotate left lower arm around y-axis
't' - Rotate left lower arm around z-axis
Right Arm:
'd' - Rotate right upper arm around x-axis
'f' - Rotate right upper arm around y-axis
'g' - Rotate right upper arm around z-axis
'c' - Rotate right lower arm around x-axis
'v' - Rotate right lower arm around y-axis
'b' - Rotate right lower arm around z-axis
Left Leg:
'6' - Rotate left upper leg around x-axis
'7' - Rotate left upper leg around y-axis
'8' - Rotate left upper leg around z-axis
'y' - Rotate left lower leg around x-axis
'u' - Rotate left lower leg around y-axis
'i' - Rotate left lower leg around z-axis
Right Leg:
'h' - Rotate right upper leg around x-axis
'j' - Rotate right upper leg around y-axis
'k' - Rotate right upper leg around z-axis
'n' - Rotate right lower leg around x-axis
'm' - Rotate right lower leg around y-axis
',' - Rotate right lower leg around z-axis

Instep:
'o' - Rotate left instep
'p' - Rotate right instep


'=' - Start the animation.

                                2000.4 by duke ,    2012.3 translated by tantofish
				
Supplement:
Adjust the global variable "interval" will adjust the playing speed of the animation.
Put "dance.wav" into project directory, then you can play the music while the animation is playing.

';' - Display the next frame pose
':' - Display the previous frame pose
'/' - Set the current status as a new key frame, and append the corresponding parameters to the original animation script.
				2012.3 by tantofish