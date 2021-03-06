#include "Condition.h"
#include "Room.h"
#include "Container.h"
#include "Item.h"
#include "Creature.h"
#include "Header.h"
#include "Zork.h"

int main(int argc, char* argv[]){


  if(argc != 2)
  {
    cout << "Enter TWO inputs!" << endl;
    return 1;
  }

    file<> file1(argv[1]);
    xml_document<> file2;
	  file2.parse<0> (file1.data());

    xml_node<> *node = file2.first_node();

    // Making vectors of xml_nodes for each class

    vector<xml_node<>*> item_nodes;
  	vector<xml_node<>*> creature_nodes;
 	  vector<xml_node<>*> room_nodes;
 	  vector<xml_node<>*> container_nodes;

    xml_node<>* xml_nodes = node->first_node();


    // going through all nodes and putting them into their corresponding vector of xml_nodes
    while(xml_nodes){
      if( strcmp(xml_nodes->name(),"item") == 0 )
      {
        item_nodes.push_back(xml_nodes);
      }

      if(strcmp(xml_nodes->name(), "creature") == 0)
      {
        creature_nodes.push_back(xml_nodes);
      }

      if(strcmp(xml_nodes->name(), "room") == 0)
      {
        room_nodes.push_back(xml_nodes);
      }
      if(strcmp(xml_nodes->name(), "container") == 0)
      {
        container_nodes.push_back(xml_nodes);
      }

      xml_nodes = xml_nodes->next_sibling();
    }

    // converting vector of xml_nodes to vector of objects

    Item* item_obj;
    Creature* creature_obj;
    Room* room_obj;
    Container* container_obj;

    vector<Item*> items;
    vector<Creature*> creatures;
    vector<Room*> rooms;
    vector<Container*> containers;


    for(int i = 0; i < item_nodes.size(); i++)
    {
      item_obj = new Item(item_nodes[i]);
      items.push_back(item_obj);
    }


    for(int i = 0; i < creature_nodes.size(); i++)
    {
      creature_obj = new Creature(creature_nodes[i]);
      creatures.push_back(creature_obj);
    }

    for(int i = 0; i < room_nodes.size(); i++)
    {
      room_obj = new Room(room_nodes[i]);
      rooms.push_back(room_obj);
    }

    for(int i = 0; i < container_nodes.size(); i++)
    {
      container_obj = new Container(container_nodes[i]);
      containers.push_back(container_obj);
    }





    for(int i = 0; i < rooms[1]->container.size(); i++)
    {
      cout << rooms[1]->container[i];
    }


    // cout << "rooms :" << endl;
    // for(int i = 0; i < room_nodes.size(); i++)
    // {
    //   cout << rooms[i]->name << endl;
    //   for(int j = 0; j < rooms[i]->container.size(); i++)
    //   {
    //     cout << rooms[i]->container[j];
    //   }
    // }
    // cout << endl;
    // cout << "containers :" << endl;
    // for(int i = 0; i < container_nodes.size(); i++)
    // {
    //   cout << containers[i]->name << endl;
    // }
    // cout<< endl;
    // cout << "items :" << endl;
    // for(int i = 0; i < item_nodes.size(); i++)
    // {
    //   cout << items[i]->name << endl;
    // }
    //
    // cout<< endl;
    // cout << "creatures :" << endl;
    // for(int i = 0; i < creature_nodes.size(); i++)
    // {
    //   cout << creatures[i]->name << endl;
    //   Condition* cond_copy = creatures[i]->trigger->condition;
    //   cout << cond_copy->status->name <<endl;
    // }

    // Main loop to take user commands and run the game

    string u_input;
    string current_room;

    // trigger with command and trigger without command
    vector<Item*> inventory;



    zork(inventory, items,creatures, rooms, containers);



}
