It define a one to many dependancy between objects so that when one objects change state, all its dependents are notified and updated automatically.
<h3>When to use Observer Method:</h2>
<ul>
  <li>When an abstraction has two aspects, one dependent on the other. Encapsulating these aspects in separate objects lets you vary and reuse them independently.</li>
<li>When a change to one object requires changing others, and you don’t know how many objects need to be changed.</li>
<li>When an object should be able to notify other objects without making assumptions about who these objects are.In other words, you don’t want these objects tightly coupled.</li>
</ul>
<h3>Components</h3>
<img src="https://media.geeksforgeeks.org/wp-content/uploads/20240205164617/Observer-(1).webp"/>
<h4>1.Subject</h4>
The subject maintains a list of observers (subscribers or listeners). It Provides methods to register and unregister observers dynamically and defines a method to notify observers of changes in its state.
<h4>2. Observer</h4>
Observer defines an interface with an update method that concrete observers must implement and ensures a common or consistent way for concrete observers to receive updates from the subject. Concrete observers implement this interface, allowing them to react to changes in the subject’s state.

<h4>3. ConcreteSubject</h4>
ConcreteSubjects are specific implementations of the subject. They hold the actual state or data that observers want to track. When this state changes, concrete subjects notify their observers. For instance, if a weather station is the subject, specific weather stations in different locations would be concrete subjects.

<h4>4. ConcreteObserver</h4>
Concrete Observer implements the observer interface. They register with a concrete subject and react when notified of a state change. When the subject’s state changes, the concrete observer’s update() method is invoked, allowing it to take appropriate actions. In a practical example, a weather app on your smartphone is a concrete observer that reacts to changes from a weather station.

<img src="https://media.geeksforgeeks.org/wp-content/uploads/20240205163046/ObserverPatternExample.webp" height="600" width="800"/>
