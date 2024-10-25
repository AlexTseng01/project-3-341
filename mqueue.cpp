// CMSC 341 - Fall 2024 - Project 3
#include "mqueue.h"
MQueue::MQueue(prifn_t priFn, HEAPTYPE heapType, STRUCTURE structure)
{
  this->m_priorFunc = priFn;
  this->m_heapType = heapType;
  this->m_structure = structure;
  this->m_size = 0;
  this->m_heap = nullptr;
}
MQueue::~MQueue()
{
  // IMPLEMENT LATER
}
void MQueue::clear() {
  // IMPLEMENT LATER
}
MQueue::MQueue(const MQueue& rhs)
{

}
MQueue& MQueue::operator=(const MQueue& rhs) {
  
}
void MQueue::mergeWithQueue(MQueue& rhs) {
  
}
void MQueue::insertOrder(const Order& order) {
    switch(m_heapType) {
      case SKEW:
        break;
      case LEFTIST:
        break;
    }
}
int MQueue::numOrders() const
{
  return m_size;
}
prifn_t MQueue::getPriorityFn() const {
  return this->m_priorFunc;
}
Order MQueue::getNextOrder() {

}
void MQueue::setPriorityFn(prifn_t priFn, HEAPTYPE heapType) {
  this->m_priorFunc = priFn;
  this->m_heapType = heapType;
  // rebuild heap + check compat
}
void MQueue::setStructure(STRUCTURE structure){
  this->m_structure = structure;
  // rebuild heap
}
STRUCTURE MQueue::getStructure() const {
  return m_structure;
}
void MQueue::printOrderQueue() const {
  
}
void MQueue::dump() const {
  if (m_size == 0) {
    cout << "Empty heap.\n" ;
  } else {
    dump(m_heap);
  }
  cout << endl;
}
void MQueue::dump(Node *pos) const {
  if ( pos != nullptr ) {
    cout << "(";
    dump(pos->m_left);
    if (m_structure == SKEW)
        cout << m_priorFunc(pos->m_order) << ":" << pos->m_order.m_customer;
    else
        cout << m_priorFunc(pos->m_order) << ":" << pos->m_order.m_customer << ":" << pos->m_npl;
    dump(pos->m_right);
    cout << ")";
  }
}

ostream& operator<<(ostream& sout, const Order& order) {
  sout  << "Customer: " << order.getCustomer()
        << ", importance: " << order.getImportance() 
        << ", quantity: " << order.getQuantity() 
        << ", order placement time: " << order.getFIFO();
  return sout;
}
ostream& operator<<(ostream& sout, const Node& node) {
  sout << node.m_order;
  return sout;
}

void MQueue::postOrderRM(Node* node) {
    if (node != nullptr) {
        postOrderRM(node->m_left);
        postOrderRM(node->m_right);
        delete node;
    }
}