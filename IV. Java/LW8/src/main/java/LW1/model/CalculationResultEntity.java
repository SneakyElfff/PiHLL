package LW1.model;

import jakarta.persistence.*;

@Entity
@Table(name = "Calculation results")
public class CalculationResultEntity {
    @Id
//    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "id")
    private Long id;

    @Column(name = "mean")
    private Double mean;

    @Column(name = "medium")
    private Double medium;

    public CalculationResultEntity() {}

    public CalculationResultEntity(Double mean, Double medium) {
        this.mean = mean;
        this.medium = medium;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public Double getMean() {
        return mean;
    }

    public void setMean(Double mean) {
        this.mean = mean;
    }

    public Double getMedium() {
        return medium;
    }

    public void setMedium(Double medium) {
        this.medium = medium;
    }
}
