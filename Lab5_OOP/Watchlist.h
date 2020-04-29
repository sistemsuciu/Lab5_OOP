// This header contains the definition of the class "Watchlist".
#pragma once
#include "Movie.h"
#include "Repository.h"

class Watchlist : public Repository // INHERITANCE
{
private:
	DynamicVector watchlist;
public:
	Watchlist();
	~Watchlist();

	void AddMovieToWatchlist(Movie& Movie);
	void DeleteMovieFromWatchlist(int& ID);
	DynamicVector GetMoviesFromWatchlist();
};

