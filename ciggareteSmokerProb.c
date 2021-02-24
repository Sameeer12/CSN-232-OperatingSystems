// # Ciggarete-Smoker-s-problem-using-Semaphores-

// initiliazing the semaphores
int TobaccoAndPaper = 0;
int PaperAndMatches = 0;
int MatchesAndTobacco = 0;
int  DoneSmoking = 1;

void agent() 
{
      wait(DoneSmoking);
      int r = rand() % 3;


      //
      // Signal which ever combination was
      // chosen.
      //



      switch( r ) {
            case 0: signal(TobaccoAndPaper);
            break;
            case 1: signal(PaperAndMatches);
            break;
            case 2: signal(MatchesAndTobacco);
            break;
      }
}

void Smoker_A()
{
      while(true) {

            //
            // Wait for our two ingredients
            //

            wait(TobaccoAndPaper);
            smoke();

            //
            // Signal that we're done smoking
            // so the next agent can put down
            // ingredients.
            //

            signal(DoneSmoking);
      }
}


void Smoker_B()
{
      while(true) {

            //
            // Wait for our two ingredients
            //

            wait(PaperAndMatches);
            smoke();

            //
            // Signal that we're done smoking
            // so the next agent can put down
            // ingredients.
            //

            signal(DoneSmoking);
      }
}

void Smoker_C()
{
      while(true) {

            //
            // Wait for our two ingredients
            //

            wait(MatchesAndTobacco);
            smoke();

            //
            // Signal that we're done smoking
            // so the next agent can put down
            // ingredients.
            //

            signal(DoneSmoking);
      }
}
