It acts as a bridge between two incompatible interfaces, making them work together. This pattern involves a single class, known as the adapter, which is responsible for joining functionalities of independent or incompatible interfaces.
<h3>Comoponents</h3>
<img src="https://media.geeksforgeeks.org/wp-content/uploads/20240204210126/Class-Diagram-of-Adapter-Design-Pattern_.webp"/>
<h5>1. Target Interface (Printer):</h5>The interface that the client code expects.
<h5>2. Adaptee (LegacyPrinter):</h5>The existing class with an incompatible interface
<h5>3. Adapter (PrinterAdapter):</h5>The class that adapts the LegacyPrinter to the Printer interface.
<h5>4. Client Code:</h5>
The code that interacts with the Printer interface.
