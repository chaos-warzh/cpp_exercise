#include <iostream>
#include <memory>

class Context {
private:
    double income;
    double expenses;

public:
    Context(double income, double expenses)
        : income(income), expenses(expenses) {}

    double getIncome() const {
        return income;
    }

    double getExpenses() const {
        return expenses;
    }

};


class TaxStrategy {
public:
    virtual double calculate(const Context& context) = 0;

    virtual ~TaxStrategy() {}
};

// extensions
class CNTaxStrategy : public TaxStrategy {
public:
    double calculate(const Context& context) override {
        return context.getIncome() * 0.25;
    }
};

class USTaxStrategy : public TaxStrategy {
public:
    double calculate(const Context& context) override {
        return context.getIncome() * 0.40 - context.getExpenses() * 0.20;
    }
};

class UNTaxStrategy : public TaxStrategy {
public:
    double calculate(const Context& context) override {
        return context.getIncome() * 0.35 - context.getExpenses() * 0.15;
    }
};


class SalesOrder {
private:
    TaxStrategy* taxStrategy;

public:
    SalesOrder(TaxStrategy* taxStrategy)
        : taxStrategy(taxStrategy) {}

    ~SalesOrder() {
        delete taxStrategy;
    }

    double calculateTax(const Context& context) {
        return taxStrategy->calculate(context);
    }
};

int main() {
    Context context(1000, 200);
    std::unique_ptr<TaxStrategy> taxStrategy(new USTaxStrategy()); // Instantiate
    SalesOrder salesOrder(taxStrategy.get());
    std::cout << salesOrder.calculateTax(context) << std::endl;
    return 0;
}