# Compilation blackjack Game

cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Proyect name and language
project(blackjack LANGUAGES CXX)


# Add card library
add_library(card
    STATIC
    "src/Card.cpp"
    "include/Card.h"
    )

# Add deck library
add_library(deck
    STATIC
    "src/Deck.cpp"
    "include/Deck.h"
    )

# Add Hand library
add_library(hand
    STATIC
    "src/Hand.cpp"
    "include/Hand.h"
    )

# Add Player library
add_library(player
    STATIC
    "src/Player.cpp"
    "include/Player.h"
    )

# Add Group library
add_library(group
    STATIC
    "src/Group.cpp"
    "include/Group.h"
    )

# Add Answer library
add_library(answer
    STATIC
    "src/Answer.cpp"
    "include/Answer.h"
    )

# Add more libraries

add_executable(blackjack_game "src/blackjack.cpp")

target_link_libraries(blackjack_game card)
target_link_libraries(blackjack_game deck)
target_link_libraries(blackjack_game hand)
target_link_libraries(blackjack_game player)
target_link_libraries(blackjack_game group)
target_link_libraries(blackjack_game answer)