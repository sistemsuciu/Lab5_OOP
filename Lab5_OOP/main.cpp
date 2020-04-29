#pragma once
#include "Movie.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"
#include <iostream>
#include <assert.h>

void test_repo_add()
{
	// This method is checking if the function that adds a movie in the repository is working properly.
	Repository repo{};
	assert(repo.getMovies().getSize() == 0);
	Movie m1{};
	m1.set_id(1);
	m1.set_title("Titanic");
	m1.set_genre("Romance");
	m1.set_apparition_year(1998);
	m1.set_number_of_likes(23);
	m1.set_trailer("https://www.youtube.com/watch?v=kVrqfYjkTdQ");
	repo.AddMovie(m1);
	assert(repo.getMovies().getSize() == 1);
	Movie m2{};
	m2.set_id(2);
	m2.set_title("A Quiet Place");
	m2.set_genre("Horror");
	m2.set_apparition_year(2018);
	m2.set_number_of_likes(14);
	m2.set_trailer("https://www.youtube.com/watch?v=p9wE8dyzEJE");
	repo.AddMovie(m2);
	assert(repo.getMovies().getSize() == 2);
	std::cout << "The function that adds a movie in the repository is working properly." << std::endl;
}

void test_repo_delete()
{
	// This method is checking if the function that deletes a movie from the repository is working properly.
	Repository repo{};
	assert(repo.getMovies().getSize() == 0);
	Movie m1{};
	m1.set_id(1);
	m1.set_title("Titanic");
	m1.set_genre("Romance");
	m1.set_apparition_year(1998);
	m1.set_number_of_likes(23);
	m1.set_trailer("https://www.youtube.com/watch?v=kVrqfYjkTdQ");
	repo.AddMovie(m1);
	Movie m2{};
	m2.set_id(2);
	m2.set_title("A Quiet Place");
	m2.set_genre("Horror");
	m2.set_apparition_year(2018);
	m2.set_number_of_likes(14);
	m2.set_trailer("https://www.youtube.com/watch?v=p9wE8dyzEJE");
	repo.AddMovie(m2);
	assert(repo.getMovies().getSize() == 2);
	int id = m1.get_id();
	repo.DeleteMovie(id);
	assert(repo.getMovies().getSize() == 1);
	id = m2.get_id();
	repo.DeleteMovie(id);
	assert(repo.getMovies().getSize() == 0);
	std::cout << "The function that deletes a movie from the repository is working properly." << std::endl;
}

void test_repo_update_title()
{
	// This method is checking if the function that updates the title of a movie in the repository is working properly.
	Repository repo{};
	Movie m1{};
	m1.set_id(1);
	m1.set_title("Titanic");
	m1.set_genre("Romance");
	m1.set_apparition_year(1998);
	m1.set_number_of_likes(23);
	m1.set_trailer("https://www.youtube.com/watch?v=kVrqfYjkTdQ");
	repo.AddMovie(m1);
	assert(m1.get_title() == "Titanic");
	int id = m1.get_id();
	std::string new_title = "New Title";
	m1.set_title(new_title);
	assert(m1.get_title() == "New Title");
	std::cout << "The function that updates the title of a movie from the repository is working properly." << std::endl;
}

void test_repo_update_genre()
{
	// This method is checking if the function that updates the genre of a movie in the repository is working properly.
	Repository repo{};
	Movie m1{};
	m1.set_id(1);
	m1.set_title("Titanic");
	m1.set_genre("Romance");
	m1.set_apparition_year(1998);
	m1.set_number_of_likes(23);
	m1.set_trailer("https://www.youtube.com/watch?v=kVrqfYjkTdQ");
	repo.AddMovie(m1);
	assert(m1.get_genre() == "Romance");
	int id = m1.get_id();
	std::string new_genre = "New Genre";
	m1.set_genre(new_genre);
	assert(m1.get_genre() == "New Genre");
	std::cout << "The function that updates the genre of a movie from the repository is working properly." << std::endl;
}

void test_repo_update_number_of_likes()
{
	// This method is checking if the function that updates the number of likes
	// of a movie in the repository is working properly.
	Repository repo{};
	Movie m1{};
	m1.set_id(1);
	m1.set_title("Titanic");
	m1.set_genre("Romance");
	m1.set_apparition_year(1998);
	m1.set_number_of_likes(23);
	m1.set_trailer("https://www.youtube.com/watch?v=kVrqfYjkTdQ");
	repo.AddMovie(m1);
	assert(m1.get_number_of_likes() == 23);
	int id = m1.get_id();
	int new_number = 10;
	m1.set_number_of_likes(new_number);
	assert(m1.get_number_of_likes() == 10);
	std::cout << "The function that updates the number of likes of a movie from the repository is working properly." << std::endl;
}

void test_repo_update_trailer()
{
	// This method is checking if the function that updates the trailer of a movie in the repository is working properly.
	Repository repo{};
	Movie m1{};
	m1.set_id(1);
	m1.set_title("Titanic");
	m1.set_genre("Romance");
	m1.set_apparition_year(1998);
	m1.set_number_of_likes(23);
	m1.set_trailer("https://www.youtube.com/watch?v=kVrqfYjkTdQ");
	repo.AddMovie(m1);
	assert(m1.get_trailer() == "https://www.youtube.com/watch?v=kVrqfYjkTdQ");
	int id = m1.get_id();
	std::string new_trailer = "https://www.youtube.com/watch?v=44vh3fncdzs";
	m1.set_trailer(new_trailer);
	assert(m1.get_trailer() == "https://www.youtube.com/watch?v=44vh3fncdzs");
	std::cout << "The function that updates the trailer of a movie from the repository is working properly." << std::endl;
}

void run_all_tests()
{
	std::cout << "TESTS: " << std::endl;
	test_repo_add();
	test_repo_delete();
	test_repo_update_title();
	test_repo_update_genre();
	test_repo_update_number_of_likes();
	test_repo_update_trailer();
}

void initialise_movie_database(Repository& repo)
{
	// This method initialises the movie list with some movies.
	Movie m1{};
	m1.set_id(1);
	m1.set_title("Titanic");
	m1.set_genre("Romance");
	m1.set_apparition_year(1998);
	m1.set_number_of_likes(23);
	m1.set_trailer("https://www.youtube.com/watch?v=kVrqfYjkTdQ");
	repo.AddMovie(m1);

	Movie m2{};
	m2.set_id(2);
	m2.set_title("A Quiet Place");
	m2.set_genre("Horror");
	m2.set_apparition_year(2018);
	m2.set_number_of_likes(14);
	m2.set_trailer("https://www.youtube.com/watch?v=p9wE8dyzEJE");
	repo.AddMovie(m2);

	Movie m3{};
	m3.set_id(22);
	m3.set_title("The Shawshank Redemption");
	m3.set_genre("Crime");
	m3.set_apparition_year(1994);
	m3.set_number_of_likes(100);
	m3.set_trailer("https://www.youtube.com/watch?v=6hB3S9bIaco");
	repo.AddMovie(m3);

	Movie m4{};
	m4.set_id(13);
	m4.set_title("The Godfather");
	m4.set_genre("Crime");
	m4.set_apparition_year(1972);
	m4.set_number_of_likes(76);
	m4.set_trailer("https://www.youtube.com/watch?v=sY1S34973zA");
	repo.AddMovie(m4);

	Movie m5{};
	m5.set_id(55);
	m5.set_title("Schindler's List");
	m5.set_genre("Biography");
	m5.set_apparition_year(1994);
	m5.set_number_of_likes(54);
	m5.set_trailer("https://www.youtube.com/watch?v=gG22XNhtnoY");
	repo.AddMovie(m5);

	Movie m6{};
	m6.set_id(3);
	m6.set_title("Inception");
	m6.set_genre("Action");
	m6.set_apparition_year(2010);
	m6.set_number_of_likes(99);
	m6.set_trailer("https://www.youtube.com/watch?v=YoHD9XEInc0");
	repo.AddMovie(m6);

	Movie m7{};
	m7.set_id(1000);
	m7.set_title("Matrix");
	m7.set_genre("Sci-Fi");
	m7.set_apparition_year(1999);
	m7.set_number_of_likes(5);
	m7.set_trailer("https://www.youtube.com/watch?v=m8e-FF8MsqU");
	repo.AddMovie(m7);

	Movie m8{};
	m8.set_id(202);
	m8.set_title("Se7en");
	m8.set_genre("Crime");
	m8.set_apparition_year(1995);
	m8.set_number_of_likes(15);
	m8.set_trailer("https://www.youtube.com/watch?v=znmZoVkCjpI");
	repo.AddMovie(m8);

	Movie m9{};
	m9.set_id(10);
	m9.set_title("La vita e bella");
	m9.set_genre("Comedy");
	m9.set_apparition_year(1997);
	m9.set_number_of_likes(80);
	m9.set_trailer("https://www.youtube.com/watch?v=ao71lV1NJsc");
	repo.AddMovie(m9);

	Movie m10{};
	m10.set_id(17);
	m10.set_title("The Pianist");
	m10.set_genre("Music");
	m10.set_apparition_year(2002);
	m10.set_number_of_likes(34);
	m10.set_trailer("https://www.youtube.com/watch?v=u_jE7-6Uv7E");
	repo.AddMovie(m10);
}

int main()
{
	run_all_tests();
	Repository repo;
	initialise_movie_database(repo);
	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.run();
	return 0;
}