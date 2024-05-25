It define a one to many dependancy between objects so that when one objects change state, all its dependents are notified and updated automatically.
<h3>When to use Observer Method:</h2>
<ul>
  <li>When an abstraction has two aspects, one dependent on the other. Encapsulating these aspects in separate objects lets you vary and reuse them independently.</li>
<li>When a change to one object requires changing others, and you don’t know how many objects need to be changed.</li>
<li>When an object should be able to notify other objects without making assumptions about who these objects are.In other words, you don’t want these objects tightly coupled.</li>
</ul>
