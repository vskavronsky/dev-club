public class Unit {
    private int damage;
    private int hitPoints;
    private int hitPointsLimit;
    private String name;
    
    private void ensureIsAlive() throws UnitIsDeadException {
        if ( this.hitPoints == 0 ) {
            throw new UnitIsDeadException();
        }
    }

    public Unit(String name, int hp, int dmg) {
        if ( hp < 0 ) {
            hp = 0;
        }
        if ( dmg < 0 ) {
            dmg = 0;
        }
        this.name = name;
        this.hitPointsLimit = hp;
        this.hitPoints = hp;
        this.damage = dmg;
    }

    public Unit() {
        this("Knight", 100, 100);
    }

    public final int getDamage() {
        return this.damage;
    }

    public final int getHitPoints() {
        return this.hitPoints;
    }

    public final int getHitPointsLimit() {
        return this.hitPointsLimit;
    }

    public final String getName() {
        return this.name;
    }

    public void addHitPoints(int hp) throws UnitIsDeadException {
        this.ensureIsAlive();
        
        if ( hp < 0 ) {
            hp = 0;
        }
        if ( this.hitPoints + hp > this.hitPointsLimit ) {
            this.hitPoints = this.hitPointsLimit;
            return;
        }
        this.hitPoints += hp;
    }
    
    public void takeDamage(int dmg) throws UnitIsDeadException {
        this.ensureIsAlive();
        
        if ( dmg < 0 ) {
            dmg = 0;
        }
        if ( this.hitPoints < dmg ) {
            this.hitPoints = 0;
            return;
        }
        this.hitPoints -= dmg;
    }
    
    public void attack(Unit enemy) throws UnitIsDeadException {
        this.ensureIsAlive();
        enemy.takeDamage(this.damage);
        enemy.counterAttack(this);
    }
    
    public void counterAttack(Unit enemy) throws UnitIsDeadException {
        this.ensureIsAlive();
        enemy.takeDamage(this.damage / 2);
    }
    
    @Override
    public String toString() {
        return "Characteristics of the warrior:\n"
            + "Name - " + this.name + ".\n"
            + "Max hit points - " + this.hitPointsLimit + ".\n"
            + "Hit points - " + this.hitPoints + ".\n"
            + "Damage - " + this.damage + ".";
    }
}
