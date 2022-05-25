#include "A_Path.h"



UA_Path::UA_Path()
{
    nodeInPath = TArray<UA_Node*>();
}



void UA_Path::InitPath(UA_Node* _startNode, UA_Node* _endNode)
{
    nodeInPath = GetFinalPath(_startNode, _endNode);
}



TArray<UA_Node*> UA_Path::GetFinalPath(UA_Node* _start, UA_Node* _end)
{
    TArray<UA_Node*> _path = TArray<UA_Node*>();
    UA_Node* _current = _end;
    _path.Add(_current);


    while (_current != _start)
    {
        _current = _current->GetPredecessor();
        _path.Add(_current);
    }
    //TODO Inverse
    return _path;

}
