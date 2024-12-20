# Room Queue Management System

This is a C++ project implementing a room queue management system. The program manages rooms, queues, and operations for assigning, entering, and removing individuals from rooms, along with associated features like searching, displaying, and managing class details.

## Features

- Create and manage rooms with unique IDs and assigned doctors.
- Add, remove, and search for individuals in the queue.
- Display details of all rooms and their queues.
- Manage individuals entering and leaving rooms.
- Count the number of individuals in a queue.
- Clear all queues in a room.
- Display the individual currently in the room.

## Structure

The project consists of the following classes:

1. **Node Class**: Represents an individual in the queue with details like name, gender, nationality, age, and phone number.
2. **Queues Class**: Manages the queue of individuals for a room.
3. **Boss_class**: Represents a room with a unique ID, doctor, and associated queue.
4. **Linked_class**: Manages all rooms in a linked list structure.

## How to Use

1. Clone the repository:
   ```bash
   git clone <repository-url>
