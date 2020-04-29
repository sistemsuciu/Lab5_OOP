// This header contains the definition of the class "Repository".
#pragma once
#include "Movie.h"
#include "DynamicVector.h"
class Repository
{
public:
	DynamicVector movies;

	Repository();
	~Repository();

	void AddMovie(Movie& Movie);
	void DeleteMovie(int& ID);
	void UpdateTitle(int& ID, std::string& Title);
	void UpdateTrailer(int& ID, std::string& Trailer);
	void UpdateGenre(int& ID, std::string& Genre);
	void UpdateNumberOfLikes(int& ID, int& Number);
	DynamicVector getMovies();
	bool findMovieById(int& ID);
};
