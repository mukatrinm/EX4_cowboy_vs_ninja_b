#include <limits>
#include <random>
#include <stdexcept>

#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/Cowboy.hpp"
#include "sources/OldNinja.hpp"
#include "sources/Point.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/YoungNinja.hpp"

using namespace ariel;

TEST_SUITE("Point Tests") {
    Point p1{0, 0};
    Point p2{2, 1};
    Point p3{2, 3};
    Point p4{-1, 2};
    Point p5{1, -1};
    Point p6{-1, -2};

    TEST_CASE("distance tests") {
        CHECK_EQ(p2.distance(p3), 2);
        CHECK_EQ(p4.distance(p6), 4);

        CHECK_EQ(p1.distance(p2), p2.distance(p1));
        CHECK_EQ(p2.distance(p3), p3.distance(p2));
        CHECK_EQ(p5.distance(p1), p1.distance(p5));
        CHECK_EQ(p5.distance(p1), p1.distance(p5));
        CHECK_EQ(p5.distance(p6), p6.distance(p5));
    }

    TEST_CASE("moveTowards tests") {
        double distance = p1.distance(p2);

        Point p3{Point::moveTowards(p1, p2, distance / 2.0)};
        CHECK_EQ(p3.distance(p2), doctest::Approx(distance / 2.0).epsilon(0.01));

        Point p4{Point::moveTowards(p1, p2, distance * 2)};
        CHECK_EQ(p1.distance(p4), p1.distance(p2));

        CHECK_THROWS_AS(Point::moveTowards(p1, p2, -1), std::invalid_argument);
    }
}

TEST_SUITE("Cowboy tests") {
    Point p1{1, 2};
    Cowboy cowboy1{"cow", p1};

    TEST_CASE("initials") {
        CHECK(cowboy1.isAlive());
        CHECK_EQ(cowboy1.getName(), "cow");
        CHECK_EQ(cowboy1.getLocation().distance(p1), 0);
        CHECK(cowboy1.hasboolets());
    }

    TEST_CASE("shooting tests") {
        Cowboy cowboy2{"boy", p1};

        SUBCASE("reload and shoot") {
            cowboy1.shoot(&cowboy2);
            cowboy1.shoot(&cowboy2);
            cowboy1.shoot(&cowboy2);
            cowboy1.shoot(&cowboy2);
            cowboy1.shoot(&cowboy2);
            cowboy1.shoot(&cowboy2);
            CHECK_FALSE(cowboy1.hasboolets());
            cowboy1.reload();
            CHECK(cowboy1.hasboolets());

            CHECK(cowboy2.isAlive());
            cowboy1.shoot(&cowboy2);
            cowboy1.shoot(&cowboy2);
            cowboy1.shoot(&cowboy2);
            cowboy1.shoot(&cowboy2);
            cowboy1.shoot(&cowboy2);
            CHECK_FALSE(cowboy2.isAlive());  // after 11 shots he should be dead

            cowboy2.shoot(&cowboy1);
            CHECK(cowboy1.isAlive());
        }

        SUBCASE("shooting while dead") {
            cowboy1.hit(110);
            CHECK_FALSE(cowboy1.isAlive());
            cowboy1.shoot(&cowboy2);
            cowboy1.shoot(&cowboy2);
            cowboy1.shoot(&cowboy2);
            cowboy1.shoot(&cowboy2);
            cowboy1.shoot(&cowboy2);
            cowboy1.shoot(&cowboy2);
            cowboy1.reload();
            cowboy1.shoot(&cowboy2);
            cowboy1.shoot(&cowboy2);
            cowboy1.shoot(&cowboy2);
            cowboy1.shoot(&cowboy2);
            cowboy1.shoot(&cowboy2);
            CHECK(cowboy2.isAlive());  // should be alive because cow is dead.
        }
    }
}

TEST_SUITE("Ninja tests") {
    Point p1{1, 2};
    YoungNinja young_ninj{"young", p1};
    OldNinja old_ninj{"old", p1};
    TrainedNinja trained_ninj{"train", p1};

    TEST_CASE("initialization tests") {
        SUBCASE("YoungNinja") {
            CHECK(young_ninj.isAlive());
            CHECK_EQ(young_ninj.getName(), "young");
            CHECK_EQ(young_ninj.getLocation().distance(p1), 0);
        }

        SUBCASE("OldNinja") {
            CHECK(old_ninj.isAlive());
            CHECK_EQ(old_ninj.getName(), "old");
            CHECK_EQ(old_ninj.getLocation().distance(p1), 0);
        }

        SUBCASE("TrainedNinja") {
            CHECK(trained_ninj.isAlive());
            CHECK_EQ(trained_ninj.getName(), "train");
            CHECK_EQ(trained_ninj.getLocation().distance(p1), 0);
        }
    }

    TEST_CASE("slashing tests") {
        SUBCASE("YoungNinja with YoungNinja tests") {
            SUBCASE("can slash (in range)") {
                YoungNinja young_ninj_2{"youngninj2", p1};

                for (size_t i = 0; i < 3; i++) {
                    young_ninj.slash(&young_ninj_2);
                }

                CHECK_FALSE(young_ninj.isAlive());
            }

            SUBCASE("can't slash (not in range)") {
                YoungNinja young_ninj_2{"youngninj2", Point{10, 10}};

                for (size_t i = 0; i < 3; i++) {  //  3 slashes is enough to kill
                    young_ninj.slash(&young_ninj_2);
                }

                CHECK(young_ninj.isAlive());
            }
        }

        SUBCASE("OldNinja with OldNinja tests") {
            SUBCASE("can slash (in range)") {
                OldNinja old_ninj_2{"oldninj2", p1};

                for (size_t i = 0; i < 5; i++) {
                    old_ninj.slash(&old_ninj_2);
                }

                CHECK_FALSE(old_ninj.isAlive());
            }

            SUBCASE("can't slash (not in range)") {
                OldNinja old_ninj_2{"oldninj2", Point{10, 10}};

                for (size_t i = 0; i < 5; i++) {  //  3 slashes is enough to kill
                    old_ninj.slash(&old_ninj_2);
                }

                CHECK(old_ninj.isAlive());
            }
        }

        SUBCASE("TrainedNinja with TrainedNinja tests") {
            SUBCASE("can slash (in range)") {
                TrainedNinja trained_ninj_2{"trainedninj2", p1};

                for (size_t i = 0; i < 4; i++) {
                    trained_ninj.slash(&trained_ninj_2);
                }

                CHECK_FALSE(trained_ninj.isAlive());
            }

            SUBCASE("can't slash (not in range)") {
                TrainedNinja trained_ninj_2{"trainedninj2", Point{10, 10}};

                for (size_t i = 0; i < 4; i++) {  //  3 slashes is enough to kill
                    trained_ninj.slash(&trained_ninj_2);
                }

                CHECK(trained_ninj.isAlive());
            }
        }

        SUBCASE("OldNinja with TrainedNinja tests") {
            SUBCASE("can slash (in range)") {
                TrainedNinja trained_ninj_2{"trainedninj2", p1};

                for (size_t i = 0; i < 4; i++) {
                    old_ninj.slash(&trained_ninj_2);
                }

                CHECK_FALSE(trained_ninj.isAlive());
            }

            SUBCASE("can't slash (not in range)") {
                TrainedNinja trained_ninj_2{"trainedninj2", Point{10, 10}};

                for (size_t i = 0; i < 4; i++) {  //  3 slashes is enough to kill
                    old_ninj.slash(&trained_ninj_2);
                }

                CHECK(trained_ninj.isAlive());
            }
        }
    }
}

TEST_SUITE("Team tests") {
    Point p1{1, 2};

    TEST_CASE("initialization tests") {
        Cowboy cowboy{"cow", p1};
        YoungNinja young_ninj{"young", p1};
        OldNinja old_ninj{"old", p1};
        TrainedNinja trained_ninj{"train", p1};

        Team team1{&cowboy};
        Team team2{&old_ninj};

        CHECK_EQ(team1.stillAlive(), 1);
        team1.add(&young_ninj);
        CHECK_EQ(team1.stillAlive(), 2);

        CHECK_EQ(team2.stillAlive(), 1);
        team2.add(&young_ninj);
        CHECK_EQ(team2.stillAlive(), 2);
    }

    TEST_CASE("team capacity test") {
        Cowboy cowboy{"cow", p1};
        Cowboy cowboy2{"cow", p1};

        Team team1{&cowboy};
        Team team2{&cowboy2};

        for (size_t i = 0; i < 9; i++) {
            Cowboy *cowboyy1 = new Cowboy{"cow1", p1};
            Cowboy *cowboyy2 = new Cowboy{"cow2", p1};
            team1.add(cowboyy1);
            team2.add(cowboyy2);
        }
        CHECK_EQ(team1.stillAlive(), 10);
        CHECK_EQ(team2.stillAlive(), 10);

        Cowboy cowboy3{"cow", p1};
        Cowboy cowboy4{"cow", p1};
        CHECK_THROWS_AS(team1.add(&cowboy3), std::runtime_error);
        CHECK_THROWS_AS(team2.add(&cowboy4), std::runtime_error);
    }

    TEST_CASE("one team per charachter test") {
        Cowboy cowboy{"cow", p1};
        Cowboy cowboy2{"cow2", p1};
        Cowboy cowboy3{"cow3", p1};

        Team team1{&cowboy};

        CHECK_THROWS_AS(Team2{&cowboy}, std::runtime_error);

        Team2 team2{&cowboy2};
        CHECK_THROWS_AS(Team{&cowboy2}, std::runtime_error);

        team1.add(&cowboy3);
        CHECK_THROWS_AS(team2.add(&cowboy3), std::runtime_error);
    }

    TEST_CASE("attack test") {
        Cowboy cowboy{"cow", p1};
        YoungNinja ninja{"youngninj", p1};

        SUBCASE("Team") {
            Team team1{&cowboy};
            Team team2{&ninja};

            for (size_t i = 0; i < 9; i++) {
                Cowboy *cowboyy = new Cowboy{"cow", p1};
                team1.add(cowboyy);
            }

            team1.attack(&team2);

            CHECK_EQ(team2.stillAlive(), 0);
        }

        SUBCASE("Team2") {
            Team2 team1{&cowboy};
            Team2 team2{&ninja};

            for (size_t i = 0; i < 9; i++) {
                Cowboy *cowboyy = new Cowboy{"cow", p1};
                team1.add(cowboyy);
            }

            team1.attack(&team2);

            CHECK_EQ(team2.stillAlive(), 0);
        }
    }
}
