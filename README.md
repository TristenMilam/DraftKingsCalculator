*Created by Tristen Milam

This program was created to calculate the most optimal lineups for DraftKings daily fantasy football. There are so many possibilities, that to make it run in a reasonable amount of time it will eliminate some players based on point/price density. It also adds in some variation in lineups so that all lineups don't revolve around the same few players.

Process to obtain lineup:
1) Run the webscraper.py, which webscrapes player projections and DraftKings cost from ESPN
2) Make make-lineups using the makefile
3) Run ./make-lineups and the optimal results will be put into the OutputStats folder
