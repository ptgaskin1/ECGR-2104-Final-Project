# ECGR-2104-Final-Project
Gin Rummy game outline

Classes needed
	
	Card (maybe a struct)
		private:
			int value
			int suite (1 = spades; 2 = diamonds; 3 = hearts; 4 = clubs)
			bool face (0 = number; 1 = face [including aces])
	Hand
		private:
			vector of 10 - 11 cards (10 base +1 drawn card each turn)
			organize runs and stacks in hand for player
			
Functions
	
	Knock
		- must have 10 or less deadwood
		- determine score on knock
		- auto lay-off deadwood for defending player
		- determine if there is an undercut (knocker deadwood > defending deadwood)
	Gin
		- check if knock is gin
	Big Gin
		- check if knock is big gin
	Bonuses
		- add the various end game bonuses
	Deadwood
		- dynamically calculates deadwood
	Stack
		- sorts cards into stack
	Run
		- sorts cards into run
		
Base variables
	
	2 stacks - discard pile and draw pile
	Player score
	CPU score
	Store number of hands won
	
AI

	Check discard pile:
		if card adds to stack or run, draw
		else draw from draw pile
		
	Discard
		if not in stack or run
			discard highest deadwood
		else if almost stack or run
			discard highest irrelevant deadwood
		else
			dump random card not in meld
			
	Knock
		If big gin
			knock
		else if gin
			knock
		else if deadwood <=7 knock && draw pile < x
			knock
		else
			discard
