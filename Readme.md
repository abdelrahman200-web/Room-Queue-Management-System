# Campaign Management System with Linked List and Queue

This project is a C++ implementation of a campaign management system, utilizing **linked lists** and **queues** for efficient data handling. The program is designed to manage campaigns, organize participants, and streamline operations for entering, processing, and removing individuals from campaigns.

## Core Concept

The system demonstrates how **linked lists** and **queues** can be effectively used to manage campaigns. Each campaign is treated as a "room," and participants form a queue. The system allows for:

1. **Linked Lists**: Managing multiple campaigns (rooms) dynamically, each identified by unique details.
2. **Queues**: Handling participants within each campaign, ensuring a **First-In-First-Out (FIFO)** approach.

## Features

### Campaign Management
- Create and manage campaigns (linked list nodes) with details such as:
  - Campaign Name
  - Campaign ID
  - Campaign Manager
- Add, remove, or search campaigns in the system.

### Participant Queue Management
- Add participants to a campaign queue with details like:
  - Name
  - Gender
  - Nationality
  - Age
  - Phone Number
- Remove participants from the queue (FIFO order).
- View the current participant being processed in the campaign.
- Count the total participants in a queue.
- Clear all participants from a queue.

### Display and Reporting
- Display all campaigns and their participant queues.
- Show details of participants waiting in a specific campaign.
- Provide an overview of the system, including campaign statistics.

---

## How It Works

### Data Structures Used
1. **Linked List**: Each node represents a campaign.
2. **Queue**: Each campaign node has a queue for managing participants.

### Workflow
1. **Campaign Creation**: New campaigns are added to the linked list.
2. **Adding Participants**: Participants are enqueued into the campaign queue.
3. **Processing Participants**: Participants are dequeued (processed) from the campaign in FIFO order.
4. **Dynamic Updates**: Campaigns and their queues can be dynamically updated at runtime.

---

## Code Example

Here's an example of how the campaign and participant system works:

```cpp
// Initialize the system
Linked_class campaignSystem;

// Create a new campaign
campaignSystem.newclass("Health Awareness Campaign", 1, "Dr. Sarah");

// Add participants to the campaign
campaignSystem.add("John Doe", "Male", "USA", 30, 1234567890, 1);
campaignSystem.add("Jane Smith", "Female", "Canada", 28, 9876543210, 1);

// Display campaigns
campaignSystem.displayAllClasses();

// Process a participant
campaignSystem.enter(1); // Dequeues and processes the first participant

// Show the current participant being served
campaignSystem.current(1);
