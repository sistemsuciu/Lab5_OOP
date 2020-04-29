// This file contains the implementation of the class "Watchlist"
#include "Watchlist.h"
#include <iostream>

Watchlist::Watchlist()
{
	// The default constructor.
}


Watchlist::~Watchlist()
{
	// The default constructor.
}

void Watchlist::AddMovieToWatchlist(Movie& Movie)
{
	// This method adds a movie in the watchlist.
	this->watchlist.add(Movie);
}

DynamicVector Watchlist::GetMoviesFromWatchlist()
{
	// This method returns the list of movies from the watchlist.
	return watchlist;
}

void Watchlist::DeleteMovieFromWatchlist(int& ID)
{
	// This method deletes a movie from the watchlist.
	Movie* movies_vector = this->watchlist.getAllElems();
	if (findMovieById(ID) == true)
		for (int i = 0; i < this->watchlist.getSize(); i++)
		{
			Movie movie = movies_vector[i];
			if (movie.get_id() == ID)
				this->watchlist.deleteElement(movie, i);
		}
	else
		std::cout << "No movie with the given ID was found in the watchlist." << std::endl;
}