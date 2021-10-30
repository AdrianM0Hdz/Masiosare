/* Complete class that has all functinalities and routines
**
*/

#pragma once

#include "components/Chasis.h"
#include "components/BinaryScreenCounter.h"
#include "components/ColorDetector.h"
#include "components/Gate.h"

class Robot
{
	private:
		Chasis* chasis;
		BinaryScreenCounter* screenCounter;
		ColorDetector* colorDetector;
		Gate* gate;
		
		// 						row col
		int positionStage1[] = {0 , 4};
		// map of the first stage with the player in its initial posisiton 
		char stageOneMap[][] = {{"U", "U", "U", "U", "U", "V"},
								{"U", "U", "U", "U", "U", "B"},
								{"U", "U", "U", "U", "U", "B"}};
		// record mooves done since reaching the exit to be able to reach it again
		
		char movesSinceExit[45];
		
		// record number of moves done since the exit to be able to iterate over the array
		// recording them
		
		int nMovesSinceExit = 0;

		// boolean value that tells if a

		bool exitFound = false; 
	
	public:
		Robot(int forwardLeft, int backwardLeft, 
			  int forwardRight, int backwardRight,
			  int frontTriggerPin, int frontEchoPin, 
			  int leftTriggerPin, int leftEchoPin, 
			  int rightTriggerPin, int frontEchoPin)
		{
			this->chasis = new Chasis(int forwardLeft, int backwardLeft, 
			   						  int forwardRight, int backwardRight,
			   						  int frontTriggerPin, int frontEchoPin, 
			   						  int leftTriggerPin, int leftEchoPin, 
			   						  int rightTriggerPin, int frontEchoPin,
			   						  "W" // initial cardinal orientation
			   					);
				
			this->ColorDetector = new ColorDetector();
		}
		
		void setup()
		{
			this->chasis->setup();
			this->ColorDetector->setup();
		}

		void updatePosition(bool advace) 
		{
			// if advance is false we assume the movement is backwards
			// position is changed due to orientation
			int delta = -1;	
			if (advance) { 
				delta = 1;
			} 

			switch (this->chasis->cardinalOrientation) {
				case "N":
					this->positionStage1[0] -= delta; 
					break;
				case "E":
					this->positionStage1[1] += delta; 
					break;
				case "S":
					this->positionStage1[0] += delta; 
					break;
				case "W":
					this->positionStage1[1] -= delta;
					break;
				default:
					break;
			}
		}

		void checkIfExitFound() 
		{
			// returns true if the robot is currently at the exit of the maze
			if (this->positionStage1[0] == 2 && this->positionStage1[1] == 0) {
				this->exitFound = true;
			}
			// nothing happens if the robot is not at the exit, this prevents reseting it back to dalse 
			// when no longer at the exit
		}

		bool checkIfAtExit() 
		{
			// Returns true if at exit, so that the robot does not continue into 
			// stage 2
			if (this->positionStage1[0] == 2 && this->positionStage1[1] == 0) {
				return true;
			}
			return false;
		}

		void exproreAllStage1() 
		{

			char moves[3] = {'f', 'l', 'r'}; 
			for (int i = 0; i < 3; i++) {
				if (this->chasis->checkMove(moves[i])) {
					char move = moves[i];
					this->chasis->makeMove(move);
					if (this->exitFound) {
						this->movesSinceExit[nMovesSinceExit] = move;
						this->nMovesSinceExit++;
					}

					this->upDatePosition(true);
					this->checkIfExitFound();
					if (this->checkIfAtExit()) {
						// prevent it from going on
						break;
					}
					this->solveStageOne();
					this->chasis->makeOppositeMove(move);
					this->upDatePosition(false);
				}

			}

		}

		void getToExitStage1() 
		{
			// check all stored moves and return to the exit
			for (int i = this->nMovesSinceExit; i > -1; i--) {
				this->chasis->makeOppositeMove(movesSinceExit[i]);
			}
		}
		
		void solveStageOne()
		{
			this->exploreAllStage1();
			this->getToExitStage1();
		}

		void solveStageTwo()
		{

		}

		void solveStageThree()
		{

		}
};