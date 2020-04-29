// This file contains the implementation of the class "Repository"
#include "Repository.h"
#include <iostream>

Repository::Repository()
{
	// The default constructor.
}

Repository::~Repository()
{
	// The default destructor.
}

void Repository::AddMovie(Movie& Movie)
{
	// This method adds a movie in the movie list.
	this->movies.add(Movie);
}

void Repository::DeleteMovie(int& ID)
{
	// This method deletes a movie from the movie list, by its ID.
	Movie* movies_vector = this->movies.getAllElems();
	if (findMovieById(ID) == true)
		for (int i = 0; i < this->movies.getSize(); i++)
		{
			Movie movie = movies_vector[i];
			if (movie.get_id() == ID)
				this->movies.deleteElement(movie, i);
		}
	else
		std::cout << "No movie with the given ID was found." << std::endl;
}

void Repository::UpdateTitle(int& ID, std::string& Title)
{
	// This method updates the title of a movie.
	Movie* movies_vector = this->movies.getAllElems();
	if (findMovieById(ID) == true)
		for (int i = 0; i < this->movies.getSize(); i++)
		{
			Movie movie = movies_vector[i];
			if (movie.get_id() == ID)
			{
				int id = movie.get_id();
				std::string title = Title;
				std::string genre = movie.get_genre();
				int year = movie.get_apparition_year();
				int likes = movie.get_number_of_likes();
				std::string trailer = movie.get_trailer();
				this->movies.deleteElement(movie, i);
				Movie new_movie{ id, title, genre, year, likes, trailer };
				AddMovie(new_movie);
			}
		}
}

void Repository::UpdateGenre(int& ID, std::string& Genre)
{
	// This method updates the genre of a movie.
	Movie* movies_vector = this->movies.getAllElems();
	if (findMovieById(ID) == true)
		for (int i = 0; i < this->movies.getSize(); i++)
		{
			Movie movie = movies_vector[i];
			if (movie.get_id() == ID)
			{
				int id = movie.get_id();
				std::string title = movie.get_title();
				std::string genre = Genre;
				int year = movie.get_apparition_year();
				int likes = movie.get_number_of_likes();
				std::string trailer = movie.get_trailer();
				this->movies.deleteElement(movie, i);
				Movie new_movie{ id, title, genre, year, likes, trailer };
				AddMovie(new_movie);
			}
		}
}

void Repository::UpdateNumberOfLikes(int& ID, int& Number)
{
	// This method updates the number of likes of a movie.
	Movie* movies_vector = this->movies.getAllElems();
	if (findMovieById(ID) == true)
		for (int i = 0; i < this->movies.getSize(); i++)
		{
			Movie movie = movies_vector[i];
			if (movie.get_id() == ID)
			{
				int id = movie.get_id();
				std::string title = movie.get_title();
				std::string genre = movie.get_genre();
				int year = movie.get_apparition_year();
				int likes = Number;
				std::string trailer = movie.get_trailer();
				this->movies.deleteElement(movie, i);
				Movie new_movie{ id, title, genre, year, likes, trailer };
				AddMovie(new_movie);
			}
		}
}

void Repository::UpdateTrailer(int& ID, std::string& Trailer)
{
	// This method updates the trailer of a movie.
	Movie* movies_vector = this->movies.getAllElems();
	if (findMovieById(ID) == true)
		for (int i = 0; i < this->movies.getSize(); i++)
		{
			Movie movie = movies_vector[i];
			if (movie.get_id() == ID)
			{
				int id = movie.get_id();
				std::string title = movie.get_title();
				std::string genre = movie.get_genre();
				int year = movie.get_apparition_year();
				int likes = movie.get_number_of_likes();
				std::string trailer = Trailer;
				this->movies.deleteElement(movie, i);
				Movie new_movie{ id, title, genre, year, likes, trailer };
				AddMovie(new_movie);
			}
		}
}

DynamicVector Repository::getMovies()
{
	// This method returns the vector of all movies.
	return movies;
}

bool Repository::findMovieById(int& ID)
{
	// This method searches for a movie in the list and returns true if the movie was found; false otherwise.
	Movie* movies_vector = this->movies.getAllElems();
	if (movies_vector == NULL)
		return false;
	for (int i = 0; i < this->movies.getSize(); i++)
	{
		Movie movie = movies_vector[i];
		if (movie.get_id() == ID)
			return true;
	}
	return false;
}
